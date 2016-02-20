//Room: /d/dali/shilin1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","李子箐石林");
	set("long",@LONG
相传优人于隆冬遥见石上有李二株，结实鲜红，晚不及收，次日
寻之不复见，故称李子箐。面积约一千二百亩，包括大石林，小石林，
和外石林，是路南石林最精华者之一。千峰比肩，大小高矮，较为接
近，远观但见一片密密簇簇，似缺少变化跃动，近赏则大不相同，那
神奇的大自然的精雕细琢，使得顽石无论状鸟，状兽，或拟人，拟物，
均表情逼肖，疑真还假。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "east"    : __DIR__"changhu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38100);
	set("coor/y", -54000);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/sl1",1);
	}
}