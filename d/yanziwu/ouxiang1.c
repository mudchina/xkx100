// Room: /d/yanziwu/ouxiang1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "藕香小筑");
	set("long", @LONG
藕香小筑建得小巧玲珑。小筑四周栽满了湘妃竹，湖面和风催动，
顿时就哗啦啦响成一片。这里是蔓陀山庄大小姐的闺房。小筑正中放着
一张小几。几边是一大块地毯，垫着两个蒲团。四壁清冷，浑不似女孩
儿家的闺房。
LONG );
	set("exits", ([
		"northeast" : __DIR__"path17",
		"south"     : __DIR__"path18",
		"up"        : __DIR__"ouxiang2",
	]));
	set("objects", ([
		__DIR__"npc/youcao" : 1,
	]));
	set("coor/x", 1200);
	set("coor/y", -1230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}