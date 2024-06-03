#pragma once
/*
 �f�[�^�̍\���ƃO���[�o���ϐ��錾
*/

#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

//�萔 (�ς�邱�Ƃ��Ȃ�����)
#define SCREEN_X 800            //��ʂ̑傫��
#define SCREEN_Y 600            //��ʂ̑傫��
#define CIRCLE_POS_X 400        //�~��X���W
#define CIRCLE_POS_Y 300        //�~��Y���W
#define CIRCLE_RADIUS_START 10  //�X�^�[�g���̉~�̔��a
#define CIRCLE_RADIUS_MAX 200   //�~�̍ő�̑傫��
#define RESULT_STRING_X 15      //
#define RESULT_STRING_Y 15      //
#define STRAT_STRING_X 230      //
#define STRAT_STRING_Y 520      //

//�ϐ�
typedef struct circle //�~�̍\����
{
    int posX;       //�~��X���W
    int posY;       //�~��Y���W
    int radius;     //�~�̔��a
    double area;    //�~�̖ʐ�
}circle;

//�Q�[���t���O
extern bool enterPressedLastFrame;     //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
extern bool gameStartFlag;             //�Q�[���J�n�t���O
extern bool circleGenerationFlag;      //�~�̐����t���O
extern bool gameEndFlag;               //�Q�[���I���t���O
extern bool enterPressAllowed;         //�G���^�[�L�[��������Ă��邩��������

//�Q�[���J�E���g
extern int enterPressCount;    //�G���^�[�����񉟂��ꂽ��
//�\���̂�ϐ��ɂ���
extern circle Circle;
//�~�̍ő�ʐ�
extern double circleAreaMax;
//�~�̖ʐϊ���
extern double circlePorpotoin;

//�t���[���J�E���g
extern double frameCount;
//�J�E���g�O
extern int prevCount;
//�J�E���g��
extern int nowCout;

//�摜�n���h���ϐ�
extern int startScreenImage;
//�A���t�@�l
extern int alpha;