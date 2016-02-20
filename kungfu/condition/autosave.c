// autosave.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
	object obj, *guards;

	switch (duration)
	{
		case 1:
			message("channel:snow",HIG"【存盘】您的档案已自动存盘。\n"NOR,me);
			me->save();
			break;
		case 4:
			if (me->query("food") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"突然$N发出一阵“咕咕”声响，忙用双手捂了捂肚子：“好饿哦，要不找点吃的去？”\n"NOR, me);
			break;
		case 7:
			if (me->query("water") <= 20 && !(wizardp(me) && me->query("env/invisibility")))
				message_vision( HIY"$N伸伸舌头舔了舔干裂的嘴唇，看来要喝点什么了。\n"NOR, me);
			break;
		default:
			if (duration == 13) duration = 0;	
			break;
	}
	if( me->query_temp("guardfor") ) obj = me->query_temp("guardfor");
	if( me->query_temp("guardto") ) obj = environment(me);
	if( me->query_temp("guardfor") || me->query_temp("guardto") )
	{
		me->add("qi", -me->query("max_qi")/10);
		me->add("jing", -me->query("max_jing")/10);
		if(me->query("qi")<200 || me->query("jing")<200)
		{
			if (me->query_temp("guardfor"))
			{
				message_vision( HIY"$N守护这么久，实在是太累了，只好放弃了守护"+obj->name()+"的想法。\n"NOR, me);
				guards = obj->query_temp("guarded");
				guards -= ({ me });
				obj->set_temp("guarded", guards);
				me->delete_temp("guardfor");
			}
			else
			{
				message_vision( HIY"$N把守这么久，实在是太累了，只好放弃了把守"+obj->query("short")+"的想法。\n"NOR, me);
				obj->delete("guarded/"+me->query_temp("guardto"));
				me->delete_temp("guardto");
			}
		}
		else
		{
			if(me->query("qi")<500 || me->query("jing")<300)
				message_vision("$N守了这么久，觉得好累。\n",me);
			else message_vision("$N守了一会，腰有点酸了。\n", me);
		}
	}
  if (me->query("max_nuqi")>0 && me->query("nuqi")>0 && 
        me->query("nuqi") < me->query("max_nuqi"))
   me->add("nuqi",-5);
   if (me->query("nuqi") < 0) me->set("nuqi",0);
	me->apply_condition("autosave", duration + 1);
	return CND_CONTINUE;
}
