#include "pch.h"
#include "app.h"
#include "ObjectMath.h"

TEST(HitSphereNormal, SimpleXAxis) {
	vec3 normal;
	auto res = hit_sphere_normal(ray(vec3(), vec3(1.f, 0.f, 0.f)),
		point3(2.f, 0.f, 0.f),
		.5f,
		normal);
  EXPECT_TRUE(res);
  EXPECT_FLOAT_EQ(-1.f, normal.x);
  EXPECT_FLOAT_EQ(0.f, normal.y);
  EXPECT_FLOAT_EQ(0.f, normal.z);
}
TEST(HitSphereNormal, MyTest) {
	vec3 normal;
	auto res = hit_sphere_normal(ray(vec3(), vec3(0.f, 0.f, -1.f)),
		point3(0, 0, -5.0f), 
		2.0f,
		normal);
	EXPECT_TRUE(res);
	EXPECT_FLOAT_EQ(0.f, normal.x);
	EXPECT_FLOAT_EQ(0.f, normal.y);
	EXPECT_FLOAT_EQ(1.f, normal.z);
}
TEST(HitSphereNormal, JustOffCenter) {
	vec3 normal;
	auto res = hit_sphere_normal(ray(vec3(), vec3(-.05f, -.05f, -1.f).unit_vector()),
		point3(0, 0, -5.0f),
		2.0f,
		normal);
	EXPECT_TRUE(res);
	EXPECT_FLOAT_EQ(0.f, normal.x);
	EXPECT_FLOAT_EQ(0.f, normal.y);
	EXPECT_FLOAT_EQ(1.f, normal.z);
}