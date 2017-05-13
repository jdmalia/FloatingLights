#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Eigen/Eigen"
#include <algorithm>

struct PointLight
{
    Eigen::Vector3f color;
    Eigen::Vector3f position;

    float           ambient;

    float           constantAtt;
    float           linearAtt;
    float           expAtt;
};

Eigen::Vector4f getPointLightColor(
        const PointLight ptLight,
        Eigen::Vector3f worldPos,
        Eigen::Vector3f normal);

#endif // POINTLIGHT_H
