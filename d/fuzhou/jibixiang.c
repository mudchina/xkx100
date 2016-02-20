// Room: /d/fuzhou/jibixiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "吉庇巷");
	set("long", @LONG
俗呼“急避巷”。宋郑性之中状元衣锦还乡时，曾因以前他落魄而
凌辱过他的人，自感亏心而急避，遂称“急避巷”。明代以谐音改巷名
为“吉庇巷”，取吉祥如意、庇境安宁之意。
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie7",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6370);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
