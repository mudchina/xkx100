// Room: /d/suzhou/hanshansi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "寒山寺");
	set("long", @LONG
你走出西门约三十里地，就到了枫桥镇，在唐元和年间，有高僧寒
山子曾来此居住，后希迁禅师在此建寺院时，更名寒山寺。唐开元年间，
诗人张继赴京应试落第，返途舟船停靠枫桥，赋诗一首：“月落乌啼霜
满天，江枫渔火对愁眠，姑苏城外寒山寺，夜半歌声到客船”。从此，
诗韵钟声，脍炙人口，寺因诗而名扬天下。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"road4",
		"enter"     : __DIR__"zhengdian",
	]));
	set("coor/x", 780);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
