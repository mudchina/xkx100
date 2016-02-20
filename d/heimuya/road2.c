// Room: /d/heimuya/road2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	 set("short", "黄土路");
	set("long", @LONG
你走在一条黄土路上。西南是一个小高岗，地势险恶，客旅断绝。
东面隐隐可以看到平定州城。
LONG );
	 set("outdoors", "heimuya");
	 set("exits", ([
	 	"southwest" : __DIR__"road1",
	 	"east" : __DIR__"pingdingzhou",
	 ]));
	 set("no_clean_up", 0);
	set("coor/x", -3010);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	 replace_program(ROOM);
}