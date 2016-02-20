// Room: /d/fuzhou/anminxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "安民巷");
	set("long", @LONG
因唐代农民起义军黄巢入闽时，到此巷即告示安民，故名。旧有锡
类坊，以宋刘藻以孝闻，后太宰余深居此改曰：“元台育德”。历史上
巷内人家多为社会贤达。元行省都事贾讷居之。巷西侧民居旧宅仍保留
匀称格局和古朴风韵。
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie5",
	]));
	set("objects", ([
		"/d/village/npc/boy" : random(2),
		"/d/village/npc/girl" : random(2),
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
