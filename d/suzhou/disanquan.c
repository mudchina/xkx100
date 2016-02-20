// Room: /d/suzhou/disanquan.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","第三泉");
	set("long",@LONG
第三泉再千人石之西得铁华岩下，此泉晶莹醇厚，系唐代茶圣陆羽
所挖，故名“陆羽井”，品定为天下第三泉，井上有三泉亭。崖题“铁
华岩”三字，取苏轼诗“铁华秀岩壁”句意。
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"east" :__DIR__"qianrenshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 790);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
