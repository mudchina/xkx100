// /kaifeng/guandao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接开封府与中州府的官道，由于这条路治安较好行人也不
少。西面通向开封，东面通向南阳。
LONG);
	set("exits", ([
  		"east"      : __DIR__"tokaifeng",
  		"northwest" : __DIR__"shulin",
	]));
        set("outdoors", "kaifeng");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
