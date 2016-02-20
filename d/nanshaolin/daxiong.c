// Room: /d/nanshaolin/daxiong.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"大雄宝殿"NOR);
	set("long", @LONG
这里是少林寺的大雄宝殿。面阔五间，进深四间。正中供奉着如来
三宝，左右各是文殊、普贤诸位菩萨。一群僧侣正自焚香诵经，仰观我
佛拈花微笑的神态，令人顿感肃然起敬。这里殿堂宽大，亦是方丈大师
召集阖寺群僧议事之所。
LONG );
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"pingtai",
		"north" : __DIR__"stoneroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6220);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



