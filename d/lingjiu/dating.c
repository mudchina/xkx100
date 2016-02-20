//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "独尊厅");
	set("long",@LONG
这就是『灵鹫宫』独尊厅。大厅全是以巨石砌成，石块之间竟无半
点缝隙，令人称奇。厅内矗立着四根石柱，皆为坚硬的花岗石所制。
LONG );
	set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30130);
	set("coor/z", 70);
	setup();
	"/clone/board/lingjiu_b"->foo();
}