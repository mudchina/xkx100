// /d/meizhuang/shushi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "书室");
	set("long", @LONG
这里是秃笔翁的书室，房中有一个大案，案上放着一个笔筒，笔筒
中插着几管大小不同的毛笔，毛笔的质料也有所不同，有狼毫，有羊毫，
有猪鬃，有鼠须，还有一支世上很难见到的獭毫笔，案上平铺着一张四
尺中堂大小的宣纸，一方端砚，一柄徽墨，一对白玉镇纸，一个寿山笔
架，都显出主人对书法的爱好。墙上挂满了主人书写的一幅幅条幅，中
堂，对联。 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/weng" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3490);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
