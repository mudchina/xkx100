// Room: /d/huangshan/sanhua.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "散花坞");
	set("long", @LONG
散花坞乃是一宽谷，谷中峰峦参差，笔架峰，骆驼石等错列其间，
远观峰峦叠嶂，近顾怪石献巧。每当春夏之季，花卉盛开，更是繁花似
锦，其中天女花最为奇艳。此花九瓣，洁白清雅遍布山坞，引人注目，
故称“散花坞”。清代程之鵔有诗赞曰：“何来仙女散天花？原是天都
仙子家。一坞花香分两度，争传秋实与春华。”
    东面便是著名的怪石梦笔生花。
LONG
	);
	set("exits", ([ 
		"west"      : __DIR__"paiyun",
		"east"      : __DIR__"mengbi",
		"northeast" : __DIR__"shisun",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
