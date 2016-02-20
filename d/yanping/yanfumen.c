// Room: /d/yanping/yanfumen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "延福门");
	set("long", @LONG
延福门就是大水门了，门前龙津渡便可放舟直通省城福州。延平府
人烟稠密，廛市繁华，龙蟠虎踞，自古以来为“兵权谋家必争”。
    驻足城头延福楼，但见“孤城削壁全临水，八面无山不到楼。”周
遭山势壁立，深湍饶郭，易守难攻，其势占溪山之雄，当水陆之会，为
入闽之襟喉，省城之屏障，向有“铜延平、铁邵武”之誉，故关防严密
不轻怠。隆武天子以国姓爷食栗此方，赐封延平郡王。
LONG );
	set("exits", ([
		"west"      : __DIR__"road2",
		"north"     : __DIR__"road1",
		"southeast" : __DIR__"longjindu",
	]));
        set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
