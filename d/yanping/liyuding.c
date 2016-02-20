// Room: /d/yanping/liyuding.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "鲤鱼顶");
	set("long", @LONG
鲤鱼顶延绵江畔，其头部峻峭如梭，直指江心，如鲤鱼逆水，波涛
湍急，回流传响不绝。山顶一座实心八层石塔，与对江九峰山的西塔遥
遥相对。
LONG );
	set("exits", ([
		"southup"   : __DIR__"dongta",
		"northeast" : __DIR__"guandao3",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
