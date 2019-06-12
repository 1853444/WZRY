#include "Tower.h"

void Tower::initTower(){
	//������Χ
	attackRadius = ATTACK_RADIUS;
	//����
	attackSpeed = ATTACK_SPEED;
	//��ʼѪ��
	originBlood = HP;
	towerHP = originBlood;
	//��������
	deathRewardMoney = 120;
	deathRewardExp = 100;

}

void Tower::minusBlood(int damageNum, Node* attacker){
	if (towerHP - damageNum >= 0) {//�ܵ�����
		towerHP -= damageNum;
	}
	else {//Ѫ��Ϊ0
		towerHP = 0;
		//enemyReward(deathRewardMoney, deathRewardExp);
	}
}

bool Tower::destoryed() {//���ݻ�
	if (towerHP == 0)
		damage = 0;
	return true;
}