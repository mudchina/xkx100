// Room: /wuliang/road1.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这里是剑湖宫内的甬道。前通宫门，后连正厅。自于大宋仁过年
间分为三宗之后，每隔五年，三宗门下弟子便在剑湖宫中比武斗剑，
获胜的一宗得在剑湖宫居住五年，至第六年上重行比试。五场斗剑，
赢得三场者为胜。由于比武关系重大，这正厅自分宗以后就一直是练
武厅。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
        set("valid_startroom", 1);
	set("exits", ([
		"out"     : __DIR__"jianhugate",
		"northup" : __DIR__"zhengting",
	]));
	set("coor/x", -71000);
	set("coor/y", -79900);
	set("coor/z", 90);
	setup();
        "/clone/board/wuliang_b"->foo();
}