// Room: /yangzhou/pingtai2.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "平台");
	set("long", @LONG
馆前平台围以石栏，台中植有一对黑松，虬曲苍劲。松间置一方石
壶，上刻“小蓬壶”，并有篆文联：“借山叠石因成趣，种竹依花为有
香”。由绿柳堤西行迳达吹台。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north" : __DIR__"lunlian",
		"west"  : __DIR__"chuitai",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}