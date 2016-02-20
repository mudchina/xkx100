//Room: /d/dali/hexi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","河西镇");
	set("long",@LONG
此镇正处妃丽湖南，住的是阿藜蛮的休猎部。阿藜蛮属台夷，村
民除了耕种沿湖的田地外，主要以捕鱼为生。临湖风光格外秀丽，北
边不远就是渔船出入的小码头。南边山中有不少野兽，休猎部的男子
经常前去狩猎。
LONG);
	set("objects", ([
	   __DIR__"npc/tshangfan": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"feilihueast",
	    "west"       : __DIR__"yujia",
	    "north"      : __DIR__"feilihusouth",
	    "south"      : __DIR__"zhulin2",
	]));
	set("coor/x", -39100);
	set("coor/y", -89200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}