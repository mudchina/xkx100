// /d/beihai/zhizhu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "智珠殿");
	set("long", @LONG
这是一座古色古香的大殿，是为供奉文殊佛像之所。殿前有一座大
香炉，香炉内烟雾缭绕，可见香火很盛。殿北有见春亭，亭北有琼岛春
荫石幢，幢首、石座、栏杆雕刻均精美。传为燕京八景之一。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"shiqiao",
		"southwest" : __DIR__"yongansi",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
