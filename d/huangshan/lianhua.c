// Room: /d/huangshan/lianhua.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "莲花峰");
	set("long", @LONG
黄山第一高峰。它超然鹤立，群峰簇拥，象一多初绽莲花，仰天怒
放，融雄伟俏丽于一体，是当之无愧的“菡萏金芙蓉”。峰上景色皆以
莲花为名，如莲花沟，莲花梗等。每逢天气晴朗，东望天目，西瞻匡庐，
北眺九华，南临诸峰，视野极为开阔。北去便是后山。
LONG
	);
	set("exits", ([ 
		"south"     : __DIR__"yuping",
		"northdown" : __DIR__"guangming",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
