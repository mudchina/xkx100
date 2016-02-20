// Room: /d/huashan/sgyhole.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个毫不起眼的山洞，但是里面的石壁上却画满了五岳剑派所
有已经失传的精妙绝招。花岗岩石壁(wall)上很多小人，全是用利器刻
制，想见当初运力之人内力十分深厚。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"out"     : __DIR__"sgyhole1",
		"southup" : __DIR__"zhandao",
	]));
	set("item_desc", ([ 
		"wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L
TEXT
	]));
	set("no_clean_up", 0);

	set("coor/x", -860);
	set("coor/y", 140);
	set("coor/z", 130);
	setup();
}
void init()
{
	add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
	int c_exp,c_skill;
	object ob = this_player();

	c_skill=(int)ob->query_skill("sword", 1);
	if (c_skill <20)
	{
		message_vision("$N的基本剑法显然太低，无法领悟石壁内容。\n",ob);
		return 1; 
	}
	c_exp=ob->query("combat_exp");

	if ((c_skill*c_skill*c_skill/10)> c_exp)
	{
		message_vision("$N的实战经验不足，无法领悟石壁内容。\n",ob);
		return 1; 
	}
	if (ob->query("jing")<20)
	{
		message_vision("$N太累了，现在无法领悟石壁内容。\n",ob);
		return 1; 
	}
	if (c_skill>101)
	{
		message_vision("$N觉得石壁内容太肤浅了。\n",ob);
		return 1; 
	}

	message_vision("$N面对着石壁趺坐静思，良久，对基本剑法似有所悟。\n",ob);
	ob->improve_skill("sword", random(10*ob->query("int")));
	ob->add("jing",-5);
	return 1;
}
