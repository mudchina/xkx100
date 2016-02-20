// Room: /d/luoyang/guanlin.c
// Last modified by winder 2002.11.11

#include <ansi.h>
inherit  ROOM;

void  create  ()
{
	set("short",  "关林");
	set("long",  @LONG
此处位于洛阳城南十四里处。关林始建于唐，相传为三国蜀将关羽
首级的葬地，前为祠庙，后为墓冢，冢高五丈有余，千株参天翠柏，蔚
然成林，故称“关林”。明万历年间始建庙植松。清乾隆时又加扩建，
致成现今的规模。关林总面积约百亩左右，三大殿和钟鼓楼，红墙碧瓦，
雕梁画栋，建筑严整。大殿塑有关羽着帝王装像，二殿为戎装像，东殿
为关羽睡卧像，西殿为秉烛诵《春秋》像，大殿前廊有复制八十三斤重
的青龙偃月刀一把。古柏苍郁，殿宇堂皇，隆冢巨碑，上书“忠义神武
关圣大帝”，气象幽然。
    常有江湖义士来此拜祭。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      :  __DIR__"road4",
	]));
	set("objects",  ([
		__DIR__"obj/xiang" : 1,
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_ketou","ketou");
	add_action("do_ketou","kneel");
}

int do_ketou()
{
	object *inv, pai, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!me->query("party"))
		return notify_fail("你不属于任何帮会！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家创立的帮会才能领取腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	inv = all_inventory(me);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai")
			return notify_fail("你恭恭敬敬地磕了卅响头，一点风声也没有！\n");
	}
	message_vision(HIG"$N屈膝跪下，一个响头恭敬地磕了下去。猛然间，一阵狂风刮地而来，只听“啪”的一声，松枝上掉下一块腰牌，正落在$N怀里！也不知道是哪个调皮鬼挂在上面的。\n"NOR, me);
	pai = new("/d/luoyang/obj/yaopai");
	pai -> move(me);
	return 1;
}
