// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆
匆而过。大道两旁有一些小货摊，似乎是一处集市。北边通向扬州城。
东南是一大片树林。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/dujiangqiao",
	]));
        set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
