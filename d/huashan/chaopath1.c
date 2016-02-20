// Roon: chaoyangpath1.c 朝阳峰小路
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","朝阳峰小路");
	set("long",@LONG
这里是朝阳峰小路，山势陡峭，两边下临深谷，一不小心都会掉了
下去。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"northeast": __DIR__"chaopath2",
		"southeast": __DIR__"square",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/jinyinhua" : random(2),
	]));
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
