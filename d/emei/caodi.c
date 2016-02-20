// Room: /d/emei/caodi.c
inherit ROOM;
int do_search();
void end(object);
void create()
{
	set("short", "草地");
	set("long", @LONG
这里就是古德林中的一片草地了。这里野草从生，高过人头，偶尔有小兽
从草中穿过，整个地方阴森恐怖，周围是一整片黑森森的树林。
LONG
	);
	set("objects", ([
		CLASS_D("emei")+"/fengling" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"gudelin3",
	]));
	set("coor/x", -6130);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search()
{
	object me = this_player();
	object ob ;
	int jing;
	if( me->is_busy() ) return notify_fail("你上一个动作还没有完成呢。\n");
	if(jing<30) return notify_fail("你无法集中精力查看！\n");
	message_vision("$N开始查看这里的一草一木，希望能找到一棵草药什么的。\n",me);
	me->start_busy(2);
	me->receive_damage("jing", 10);
	call_out("end",3,me);
	return 1;
}
void end(object me)
{
	object ob;
	switch(random(10))
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			message_vision("$N累了个半死，结果什么都没有找到。\n",me);
			break;
		default: ob=new(__DIR__"obj/caoyao");
			ob->move(me);
			message_vision("$N找到了一片草药，放在$N的身上。\n",me);
			break;
	}
}