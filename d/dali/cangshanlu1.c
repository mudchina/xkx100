//Room: /d/dali/cangshanlu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","苍山山路");
	set("long",@LONG
此处正当河边，两侧山壁几乎是直上直下，面前是一条大河自北
滔滔而来，在此折向东咆哮而去，河水奔腾汹涌，拍击河岸，发出一
阵阵骇人的轰响。这里恰缝河湾，河床较窄，河谷上并无桥梁，只有
三根粗藤条横跨两岸，这端绑在一棵大树上，似可攀援而过。
LONG);
	set("objects", ([
	   __DIR__"npc/lieren": 1,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"cangshanzhong",
	    "west"       : __DIR__"heshang",
	]));
	set("coor/x", -45000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}