// Room: /d/lingxiao/qihan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","气寒轩");
	set("long",@LONG
这里是凌霄城大弟子白万剑及其家人的住所。墙上挂着一副中堂，
上书“气寒西北”，笔法粗犷，显是名家手迹。桌上放着一壶参阳玉酒，
酒香四溢，一位面貌英俊的男子坐在桌旁，正悠闲自得地修剪桌上的一
盆梅花。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/bai1" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
}
