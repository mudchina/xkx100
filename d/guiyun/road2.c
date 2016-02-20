// Room: /d/guiyun/road2.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "湖滨小路");
	set("long", @LONG
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一
条不知有多长的小路。西边靠湖是个热闹的码头，南面是一家小酒馆。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guiyun");

	set("exits", ([
		"west" : __DIR__"matou",
		"east" : __DIR__"riverw",
		"north": __DIR__"road3",
		"south": __DIR__"jiuguan",
	]) );
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]) );
	setup();
	quarter_pass();
}

void quarter_pass()
{
//	mixed *local;
	string time = NATURE_D->game_time();
/*
	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21)
*/
	if( strsrch(time, "子时") >= 0 ||
		strsrch(time, "丑时") >= 0 ||
		strsrch(time, "寅时") >= 0 ||
		strsrch(time, "戌时") >= 0 ||
		strsrch(time, "亥时") >= 0)
	{
		set("long", @LONG
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一
条不知条不知有多长的小路。西边靠湖是个热闹的码头，南面是一家打
烊了的小酒馆。
LONG
		);
		delete("exits/south");
	}
	else {
		set("long", @LONG
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一
条不知条不知有多长的小路。西边靠湖是个热闹的码头，南面是一家开
着的小酒馆。
LONG
		);
		set("exits/south", __DIR__"jiuguan");
	}
	call_out("quarter_pass", 30);
}
