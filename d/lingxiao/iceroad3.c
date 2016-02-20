// Room: /d/lingxiao/iceroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","冰道");
	set("long",@LONG
这条冰道的两边都很安静。西边是冰车，东边是凌霄城的监狱。北
边过去，就是凌霄城的根本之地──雪山派的总堂凌霄殿了，这里防守
紧密，四处都是凌霄弟子。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"iceroad2",
		"north" : __DIR__"meiroad1",
		"west"  : __DIR__"car",
		"east"  : __DIR__"jianyuting",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31000);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

