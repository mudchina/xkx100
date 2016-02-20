// Room: /d/yanping/erbapu.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "廿八铺");
	set("long", @LONG
廿八铺高居仙霞岭上，四望群山连绵，长风振岗，十分爽利。这里
是个很小的小村落，虽然南来北往的客商繁多，可是也只有一家小小客
店，店门书着一联：“到来福地非为福，出得仙霞始为仙”。极言闽道
之艰。
LONG );
	set("exits", ([
		"north"     : __DIR__"xianxialing",
		"southdown" : __DIR__"shandao1",
		"west"      : __DIR__"kedian",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 2,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -4000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
