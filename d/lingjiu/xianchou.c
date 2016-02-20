//room: xianchou.c
inherit ROOM;

void create()
{
	set("short","仙愁门");
	set("long",@LONG
这里就快到缥缈峰绝顶了，越往上走，山势越高，缭绕在你身边的
白雾愈来愈浓，往南则是下山的路。沿着山道没走几步，在你眼前出现
一个石坊，上书『仙愁门』三个大字，盖因上山之艰辛吧。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"eastup" : __DIR__"dadao1",
		"southdown" : __DIR__"jian",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/first" :1,
	]));
	set("coor/x", -51010);
	set("coor/y", 30100);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}