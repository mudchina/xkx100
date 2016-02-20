// Room: /d/fuzhou/guanglufang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "光禄坊");
	set("long", @LONG
北宋熙宁元年(1068年)以光禄大夫身份任福州知州的程师孟，常到
坊里的法禅寺游览，见池畔有一块大岩石，便登石吟诗，故被称为“光
禄吟台”，而此坊也改名为光禄坊。程师孟题吟的“光禄吟台”四个篆
字石刻今尚存。
LONG );
	set("exits", ([
		"east" : __DIR__"nanhoujie5",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
