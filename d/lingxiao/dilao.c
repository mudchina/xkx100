// Room: /d/lingxiao/dilao.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "地牢");
	set("long", @LONG
这间地牢在监狱的最下面，但却有淡淡的阳光透入。地牢中间，一
个身影手持铁链，傲然站在石柱旁。日光透将进来，只见那人满脸花白
胡子，身材魁梧，背脊微弓，倒似这间小小石室装不下他这个大身子似
的，眼光耀如闪电，威猛无俦。 
LONG );
	set("exits", ([
		"out" : __DIR__"didi",
	]));
	set("objects", ([ 
		CLASS_D("lingxiao")+"/bai" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 120);
	setup(); 
	replace_program(ROOM);
}

