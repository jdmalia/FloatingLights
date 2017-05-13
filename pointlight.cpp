#include "pointlight.h"

Eigen::Vector4f getPointLightColor(
        const PointLight ptLight,
        Eigen::Vector3f worldPos,
        Eigen::Vector3f normal)
{
    Eigen::Vector3f posToLight = worldPos - ptLight.position;
    float dist = posToLight.norm();
    posToLight.normalize();

    float diffuse = fmax(0.0, normal.dot(-posToLight));

    float attTotal = ptLight.constantAtt + ptLight.linearAtt*dist + ptLight.expAtt*dist*dist;

    Eigen::Vector4f ret(ptLight.color[0], ptLight.color[1], ptLight.color[2], 1.0);

    return ret*(ptLight.ambient+diffuse)/attTotal;
}
