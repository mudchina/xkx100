// Room: /d/huangshan/jiyu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "鲫鱼背");
	set("long", @LONG
过了探海松，便是鲫鱼背了，一段长约十余丈，宽仅半丈，两侧凌
空，下临深渊的石质刃脊，前人所谓“天都欲上路难通”指的就是这一
段，直到二仙另开一路，方才可以轻松登天都。过了鲫鱼背，再经过前
面的“仙人把洞门”，便是天都峰了。
LONG
	);
	set("exits", ([ 
		"eastup" : __DIR__"tiandu",
		"west"   : __DIR__"guanyin",
		"north"  : __DIR__"erxian",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
