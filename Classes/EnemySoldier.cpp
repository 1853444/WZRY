#include "EnemySoldier.h"

bool EnemySoldier::init() {
	if (SoldierType == 0) {
		//��ʼѪ��
		SoldierBlood = HP_0;
		//��������
		deathRewardMoney = 30;
		deathRewardExp = 20;
		//�˺�
		damage = DAMAGE_0;
	}
	else if (SoldierType == 1)
	{
		//��ʼѪ��
		SoldierBlood = HP_1;
		//��������
		deathRewardMoney = 45;
		deathRewardExp = 30;
		//�˺�
		damage = DAMAGE_1;
	}
	else if (SoldierType == 2)
	{
		//��ʼѪ��
		SoldierBlood = HP_2;
		//��������
		deathRewardMoney = 75;
		deathRewardExp = 50;
		//�˺�
		damage = DAMAGE_2;
	}
	else
		return false;

	//������Χ
	attackRadius = ATTACK_RADIUS;
	//����
	attackSpeed = ATTACK_SPEED;

	return true;
}

bool EnemySoldier::checkInTower() {
	Vec2 pos1 = this->enemyTower->getPosition();
	if (attackRect->containsPoint(pos1)) {	
		return true;
	}

	return false;
}

void EnemySoldier::attackTower() {
	if (checkInTower) {
		Animation* animation = Animation::create();
		__String* frameName;
		switch (SoldierType) {
		case 1:
			Tower::minusBlood(DAMAGE_0);
			break;
		case 2:
			Tower::minusBlood(DAMAGE_1);
			break;
		case 3:
			Tower::minusBlood(DAMAGE_2);
			break;
		}
		animation->setDelayPerUnit(0.2f);
		animation->setRestoreOriginalFrame(true);
	}
}

void EnemySoldier::minusBlood(int damageNum) {
	if (SoldierBlood - damageNum >= 0) {//�ܵ�����
		SoldierBlood -= damageNum;
	}
	else {//Ѫ��Ϊ0
		SoldierBlood = 0;
		Moving = false;
		Attacking = false;
		Money::moneyPlus(deathRewardMoney);
	}
}