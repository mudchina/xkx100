// Room: /d/quanzhou/luoyangqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "洛阳桥");
	set("long", @LONG
这是洛阳江上的一座誉满天下的粱式石桥。桥长身宽，具桥墩四十
六座。桥上两旁翼以扶栏，栏杆石挂上头，雕镂精致雄俊的石狮；更兼
七亭九塔，点缀其间，武士石像，分立两端。桥之首尾，沿路植松七百
株。松翠桥白，水碧山青，胜状令人惊叹。相传它是泉州知府蔡襄命一
吏名夏得海冒死下海送信，得海神相助而建。它是粤闽北上的陆路交通
要道，大部分南来北往的货物，都由此经过。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"lingshan",
		"east" : __DIR__"tudimiao",
	]));
	set("coor/x", 1890);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
