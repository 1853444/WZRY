#pragma once

#include"cocos2d.h"
#include"EnemySoldier.h"
#include"Money.h"

USING_NS_CC;

#define ATTACK_RADIUS 90
#define ATK_DAMAGE 250
#define HP 8000
#define ATTACK_SPEED 100

class Tower
{
public:
	//��Ӫ
	void setColor(int color) { _color = color; }
	int getColor() { return _color; }
	//������Χ
	void setAttackRadius(float radius) { attackRadius = radius; }
	int getAttackRadius() { return attackRadius; }
	//�����ٶ�
	void setAttackInterval(int attackInterval) { attackSpeed = attackInterval; }
	int getAttackInterval() { return attackSpeed; }
	//��ǰ����
	float& towerHP;
	static void minusBlood(int damageNum);

	//�Ƿ����
	bool destoryed();
	

private:
	int _color;
	float damage = ATK_DAMAGE;
	float attackRadius;

	float originBlood = HP;

	int& deathRewardMoney;
	int deathRewardExp;
	int attackSpeed = ATTACK_SPEED;

	void initTower();
};

