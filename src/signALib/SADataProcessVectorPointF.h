#ifndef SADATAPROCESSVECTORPOINTF_H
#define SADATAPROCESSVECTORPOINTF_H
#include "SADataFeatureItem.h"
#include <QObject>
#include <QVector>
#include <QPointF>
#include <QVariant>
#include "SALibGlobal.h"
class QLocalSocket;
///
/// \brief 处理一维数组的处理类
///
class SALIB_EXPORT SADataProcessVectorPointF : public QObject
{
    Q_OBJECT
public:
    SADataProcessVectorPointF(QObject* parent = nullptr);
    int getSortCount() const;
    void setSortCount(int sortCount);
public slots:
    //设置需要计算的点，并开始计算
    void setPoints(const QVector<QPointF>& points
                   , QVariant args);
    //从点集获取y值
    static void getVectorPointY(const QVector<QPointF>& points, QVector<double>& ys);
    //获取尖峰的点 - 所谓尖峰是指三点a,b,c b>a && b>c 就说明b是尖峰
    static void getSharpPeakPoint(QVector<QPointF>& sharpPoints,const QVector<QPointF>& Points,bool isUpperPeak = true);
    //比较点的y值
    static int comparePointY(const QPointF& a,const QPointF& b)
    {
        return int( a.y() < b.y() );
    }
    //峰值排序
    static void sortPeak(QVector<QPointF>& sharpPointsSorted,const QVector<QPointF>& Points,bool isUpperPeak = true);

signals:
    ///
    /// \brief 返回的结果指针如果不用必须delete
    /// \param result
    /// \param widget 标记1
    /// \param item 标记2
    ///
    void result(SADataFeatureItem* result, QVariant args);
private:
    SADataFeatureItem* analysisData(const QVector<QPointF> &orgPoints);
private:
    int m_sortCount;///< 记录要显示的排序条目
};

#endif // SADATAPROCESS_H
