// Room: /d/baituo/kongdi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);

void create()
{
	set("short", "空地");
	set("long", @LONG
这是大厅前的空地，旁边放了些兵器架、沙袋以及几个木桩。地上
铺满了飘落的树叶和干草。四周装点着青青翠竹，错落有致。旁边有一
口水井、一把水瓢，井水清澈，散发着阵阵凉气。西边是武器库。东边
有一间储藏室，房门(door)关闭着。北边是『白驼山庄』的大厅。南边
就是大门了。
LONG);
	set("resource/water", 1);
	set("exits", ([
		"northup" : __DIR__"dating",
		"west"    : __DIR__"wuqiku",
		"south"   : __DIR__"damen",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("item_desc", ([
	    "door" : (: look_gate :),
	]));
	set_temp("lock",1);

	set("coor/x", -50010);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
}

string look_gate()
{
	if (query_temp("lock") == 0) return "门上的铁锁被打开了。\n";
	return "这扇门被铁锁牢牢锁住。\n";
}

int do_open(string arg)
{
	object me=this_player(), room;
	object *inv;
	int j;

	if(!arg || arg!="door") return notify_fail("你要开什么？\n");
	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("钥匙都没有，怎么开门？\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	inv = all_inventory(me);
        for (j = 0; j < sizeof(inv); j++)
            {
              if (inv[j]->is_character())
                  {
                   return notify_fail("屋子里位置有限，挤不下那么多人。\n");
                    }
             }
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");
	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁开了。\n", me);
		message("vision","外面传来一阵开锁的声音，只听见‘卡嗒’一声，锁开了。\n",room);
	}
	message_vision("$N轻轻推开门，走了进去，随手把门掩了起来。\n",me);
	message("vision", "有人走了进来，随手把门掩上了。\n",room);
	me->move(room);
	return 1;
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door") return notify_fail("你要锁什么？\n");
	if( !present("key",me))
		return notify_fail("钥匙都没有，怎么锁门？\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");
	if(query_temp("lock") == 1)
		return notify_fail("门已经锁好了。\n");
	set_temp("lock",1);
	message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁被锁上。\n",me);
	message("vision","外面传来一阵锁铁锁的声音，只听见‘卡嗒’一声，锁被锁上了。 \n",room);
	return 1;
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "白驼山派") && dir == "west")
		return notify_fail("此处乃本派禁地，请止步。\n");
	return ::valid_leave(me, dir);
}

int do_drink(string arg)
{
	int current_water, max_water, lvl, exp;
	object me = this_player();

	exp = me->query("combat_exp");
	lvl = me->query_skill("force", 1);
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
		me->set("water", current_water+30);
		message("vision", me->name()+"用水瓢舀了一口井水喝。\n", environment(me), ({me}) );
		if ( lvl < 30 && lvl*lvl*lvl/10 < exp)
			me->improve_skill("force", me->query("int"));
		write("你喝了一口清清的井水，虽身处炎热的大漠，也感到一丝凉意。\n");
	}
	else write("你已经喝不下了。\n");

	return 1;
}
