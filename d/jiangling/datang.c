//Edited by fandog, 02/15/2000

inherit ROOM;
void create ()
{

	set ("short", "大堂");
	set ("long", @LONG
这里是江陵知府的衙门大堂。两边是“肃静”、“回避”的牌子，
十几个衙役齐刷刷地站着，手拿水火棍，虎视耽耽的。知府大人坐在案
台后，冷冷地逼视着你。大堂上方挂一巨匾，上写“明镜高悬”四个大
字。一个师爷打扮的人站在知府大人身后，不时俯身对大人耳语几句。
LONG);

	set("exits", ([ 
		"east" : __DIR__"huapu",
		"west" : __DIR__"yamen",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 4,
		__DIR__"npc/shiye" : 1,
		__DIR__"npc/ling"  : 1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -1489);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}