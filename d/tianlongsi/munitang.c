inherit ROOM;

void create()
{
        set("short", "牟尼堂");
        set("long",@LONG
这是高僧们的静修之处。整堂全以松木制成，板门木柱，木料均不去
皮，天然质朴，和一路行来金碧辉煌的殿堂截然不同。室中五个和尚分坐
五个蒲团。四僧朝外，东首一个和尚面朝里壁一动不动。
LONG
        );
        set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
		__DIR__"npc/kurong" : 1,
		__DIR__"npc/benguan" : 1,
		__DIR__"npc/benxiang" : 1,
		__DIR__"npc/bencan" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
