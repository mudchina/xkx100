// Room: /d/wuyi/5qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "五曲");
	set("long", @LONG
五曲北岸就是云窝了，在南岸更衣台光洁硕大的岩壁上，清晰可见
“玉皇大天尊”五字题刻。这里就是道教小洞天中的第十六洞天。朱熹
《九曲棹歌》曰：“……五曲山高云气深，长时烟雨暗平林。林间有客
无人识，唉乃声中万古心。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"yunwo",
		"south"     : __DIR__"yuchayuan",
		"southwest" : __DIR__"gengyitai",
		"northeast" : __DIR__"4qu",
		"northwest" : __DIR__"6qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

