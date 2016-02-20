//ROOM: /d/yanziwu/shangyu.c

inherit ROOM;

void init();
int do_jump(string);

void create()
{
	set("short", "赏鱼台");
	set("long",@LONG
站在台上，你可以看见一片荷花菱角，不时有几尾金鱼跃出水面，
有的甚至还跳你眼前，仿佛一伸手就可以抓住。透过荷叶隐约可以看到
船坞，你不知是否有把握能跳过去。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"north": __DIR__"shuwu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1560);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	int i,jing_cost,qi_cost;
	me=this_player();

	i = (int)me->query_skill("dodge", 0) + random(200);
	jing_cost = 600 / (int)me->query("int");
	qi_cost = 500 / (int)me->query("int");
	if(((int)me->query("jing")<jing_cost) || ((int)me->query("qi")<qi_cost))
		i = 0;

	message_vision("$N深吸一口气，一个纵身，从台上向船坞跳去。\n", me);
	me->move(__DIR__"bozhou");
	message_vision("只听「砰」的一声，$N从空中飞了下来。\n", me);
	if ( i < 40)
	{
		tell_object(me,"你突然心中大叫“不好”！唉呀.....");
		me->die();
	}
	else if( i < 80)
	      {
		      tell_object(me,"你暗呼一声“不好”.....");
		      me->unconcious();
	      }
	      else
	      {
		      message_vision("$N已稳稳地站在船坞上。\n", me);
		      me->receive_damage("jing", jing_cost );
		      me->receive_damage("qi", qi_cost );
	      }

	return 1;
}