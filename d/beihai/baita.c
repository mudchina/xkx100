// /d/beihai/baita.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "琼岛白塔");
	set("long", @LONG
百塔为以琼华岛为主体组成的四面景观的中心。位于北海琼华岛之
巅。白塔上为喇嘛塔，下为高大的砖石台基，塔座为折角式须弥座，其
上承托覆钵式塔身，正面中有壶门式眼光门，门内刻有藏文咒语。塔身
上部为细长的十三天，上为两层铜质伞盖，边缘悬铜钟十四个，最上为
鎏金火焰宝珠塔刹。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"yilan",
		"southdown" : __DIR__"yongansi",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
