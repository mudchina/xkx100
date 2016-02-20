// Room: /d/yanziwu/ouxiang2.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "藕香小居");
	set("long", @LONG
藕香小筑建得小巧玲珑。小筑四周栽满了湘妃竹，湖面和风催动，
顿时就哗啦啦响成一片。小居四面临窗，窗下一排排矮柜，摆放着的都
是武功秘籍。案头一支小儿臂粗的蜡烛已经烧了一半，长长的烛泪垂了
下来，把整支蜡烛固定在书案上。
LONG );
	set("exits", ([
		"down"  : __DIR__"ouxiang1",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("coor/x", 1200);
	set("coor/y", -1230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}