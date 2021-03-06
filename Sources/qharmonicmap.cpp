#include "qharmonicmap.h"

#define DEFAULT_SNR_MIN -10.0
#define DEFAULT_SNR_MAX 10.0
//==========================================================================================================
QHarmonicProcessorMap::QHarmonicProcessorMap(QObject *parent, quint32 width, quint32 height):
    QObject(parent),
    m_width(width),
    m_height(height),
    m_length(width*height),
    m_updations(0),
    m_min(DEFAULT_SNR_MIN),
    m_max(DEFAULT_SNR_MAX),
    m_cell(0)
{
    v_map = new qreal[m_length]; // 0...width*height-1
    v_outputmap = new qreal[m_length];
    v_processors = new QHarmonicProcessor[m_length]; // 0...width*height-1

    qWarning("idealThreadCount() for system return %d", QThread::idealThreadCount());
    m_threadCount = QThread::idealThreadCount();
    v_threads = new QThread[m_threadCount];

    for(quint32 i = 0; i < m_length; i++)
    {
        v_processors[i].setID(i); // needs for control in whitch cell of the map write particular snr value
        v_processors[i].moveToThread(&v_threads[ i % m_threadCount ]);
        connect(this, SIGNAL(updateMap()), &v_processors[i], SLOT(ComputeFrequency()));
        connect(&v_processors[i], SIGNAL(snrUpdated(quint32,qreal)), this, SLOT(updateCell(quint32,qreal)));
        connect(this, SIGNAL(changeColorChannel(int)), &v_processors[i], SLOT(switchColorMode(int)));
        connect(this, SIGNAL(updatePCAMode(bool)), &v_processors[i], SLOT(setPCAMode(bool)));
    }
    for(quint16 i = 0; i < m_threadCount ; i++)
    {
        v_threads[i].start();
    }
}

QHarmonicProcessorMap::~QHarmonicProcessorMap()
{
    for(quint16 i = 0; i < m_threadCount; i++)
    {
        v_threads[i].quit();
    }
    for(quint16 i = 0; i < m_threadCount; i++)
    {
        v_threads[i].wait();
    }
    delete[] v_map;
    delete[] v_outputmap;
    delete[] v_processors;
    delete[] v_threads;
}

void QHarmonicProcessorMap::updateHarmonicProcessor(unsigned long red, unsigned long green, unsigned long blue, unsigned long area, double period)
{
    connect(this, SIGNAL(dataArrived(ulong,ulong,ulong,ulong,double)), &v_processors[m_cell], SLOT(EnrollData(ulong,ulong,ulong,ulong,double)));
    emit dataArrived(red,green,blue,area,period);    
    disconnect(this, SIGNAL(dataArrived(ulong,ulong,ulong,ulong,double)), &v_processors[m_cell], SLOT(EnrollData(ulong,ulong,ulong,ulong,double)));
    m_cell = (++m_cell) % m_length;
}

void QHarmonicProcessorMap::updateCell(quint32 id, qreal value)
{
    m_mutex.lock();

    v_map[id] = value;
    if(value > m_max) {
        m_max = value;
    } else if(value < m_min) {
        m_min = value;
    }
    m_updations++;
    if(m_updations == m_length)
    {
        for(quint32 i = 0; i < m_length; i++) {
            v_outputmap[i] = (v_map[i] - m_min)/(m_max - m_min);
        }
        emit mapUpdated(v_outputmap, m_width, m_height, m_max, m_min);
        m_updations = 0;
        m_max = DEFAULT_SNR_MAX;
        m_min = DEFAULT_SNR_MIN;
    }

   m_mutex.unlock();
}

//==========================================================================================================
