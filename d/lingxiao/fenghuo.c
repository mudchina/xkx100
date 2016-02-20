// Room: /d/lingxiao/fenghuo.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","风火居");
	set("long",@LONG
这里是雪山双杰之一的封万里的房间。房间混乱不堪，到处都是刀
剑砍凿的痕迹，好象被谁在这发泄过怒火似的。一名手持长剑，少了一
臂，而偏又面带怒色的中年男子，站在屋中，凝望窗外，正牙关紧咬，
似有无限恨事。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/feng" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}

