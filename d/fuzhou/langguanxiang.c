// Room: /d/fuzhou/langguanxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "郎官巷");
	set("long", @LONG
宋刘涛曾居于此，子孙数世皆为郎官，故名郎官巷。宋代名诗人陈
烈，清代名人严复的故居也坐落巷内。郎官巷口立有牌坊，坊柱上有副
对联：“译著辉煌，今日犹传严复宅；门庭鼎盛，后人远溯刘涛居。”
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie2",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
