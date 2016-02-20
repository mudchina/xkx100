#include <ansi.h>

void init()
{
	add_action("do_zhu","zhu");
	add_action("do_answer","answer");
}
int do_zhu(string arg)
{
	object me,ob;
	string type ,w_name, id;
	me = this_player();
	ob = this_object();
	type = ob->query("type");
	if(!(me->query_temp("m_make")) ||
	     me->query_temp("m_make") != ob->query("type") ) return 0;

	if((me->query("weapon/make")) )
	{
		message_vision("$N一脸茫然：您已经有一把自造的武器了，还来干什么？难到不可手么？\n",ob);
		return 2;
	}
	if( !arg )
		return notify_fail(ob->query("name")+"认真的说：想好名称及代号后再对我说。\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("使用(zhu "+type+"的名字 英文代号)\n");
	if(id == "corpse" || w_name == "corpse")
		return notify_fail("非法的名字或英文代号。\n");
	if (strlen(w_name)>75) return notify_fail("你选择的名字太长了吧。\n");
	if (strlen(id) > 20) return notify_fail("你选择的英文代号太长了吧。\n");
	w_name = replace_string(w_name, "$BLK$", BLK);
	w_name = replace_string(w_name, "$RED$", RED);
	w_name = replace_string(w_name, "$GRN$", GRN);
	w_name = replace_string(w_name, "$YEL$", YEL);
	w_name = replace_string(w_name, "$BLU$", BLU);
	w_name = replace_string(w_name, "$MAG$", MAG);
	w_name = replace_string(w_name, "$CYN$", CYN);
	w_name = replace_string(w_name, "$WHT$", WHT);
	w_name = replace_string(w_name, "$HIR$", HIR);
	w_name = replace_string(w_name, "$HIG$", HIG);
	w_name = replace_string(w_name, "$HIY$", HIY);
	w_name = replace_string(w_name, "$HIB$", HIB);
	w_name = replace_string(w_name, "$HIM$", HIM);
	w_name = replace_string(w_name, "$HIC$", HIC);
	w_name = replace_string(w_name, "$HIW$", HIW);
	w_name = replace_string(w_name, "$NOR$", NOR);
	w_name = replace_string(w_name, "\\n", "");
	w_name = replace_string(w_name, "$N", "");
	w_name = replace_string(w_name, "$n", "");
	w_name = replace_string(w_name, "\"", "");
	w_name = replace_string(w_name, "\'", "");
	w_name += NOR;
	message_vision("$N说道：准备要铸叫做 "+w_name+"("+id+")"+" 的"+type+"。\n",ob);
	message_vision("$N说道：你准备好了吗？(answer y)。\n",ob);
	me->set_temp("m_check",1);
	me->set_temp("m_w/name",w_name);
	me->set_temp("m_w/id",id);
	return 1;
}
int do_answer(string arg)
{
	object ob=this_object();
	object me=this_player();
	string type = ob->query("type");
	string w_name,id,make_time,o_name;
	object weapon;
	if (!me->query_temp("m_check")) return 0;
	me->delete_temp("m_check");
	if (arg != "y" && arg != "Y") return notify_fail(ob->query("name")+"说道：好吧，你再考虑清楚一下。\n");
// 开始生成武器
	me->delete_temp("m_make");
	me->delete_temp("get_orc");
	me->delete_temp("or");
	if(me->query_temp("shenmu") ) o_name="千年神木";
	if(me->query_temp("jinmu") )  o_name="海底金母";
	if(me->query_temp("hanzhu") ) o_name="寒丝羽竹";
	if(me->query_temp("ironstone") ) o_name="陨星铁石";
	w_name = me->query_temp("m_w/name");
	id = me->query_temp("m_w/id");
	make_time=NATURE_D->game_time();
	message_vision("$N沉吟了一会，对$n悄声说了几句话。$n点了点头。说：好吧！\n",me,ob);
	message_vision("\n$n回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me,ob );
	message_vision(BLU "$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n" NOR,me);
	message_vision(RED "只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n" NOR,me );
	message_vision(YEL "$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n" NOR,me);
	message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || 
	(me->query("jing"))<(me->query("max_jing")) || 
	(me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "突然$N觉得气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "只听咯的一声轻响，一柄巨"+type+"从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
	message_vision("$n见状大叫：神"+type+"初成，人血以祭！！闪开！\n",me,ob);
	message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。\n",me);
	message_vision("巨"+type+"透胸穿出，$n惨号一声，鲜血溅得你满脸都是！\n",me,ob);
	message_vision(RED "$n脚下一个不稳，倒在了地上，已经奄奄一息了。\n" NOR,me,ob);
	message_vision("巨"+type+"又飞了起来，飞到半空，当的一声落回到地上。\n炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。\n",me );

	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("weapon/make",1);		//武器制造后防止再造的标志
	me->set("weapon/name",w_name );	//武器的名称
	me->set("weapon/id",id);		//武器的代号
	me->set("weapon/lv",1);			//武器等级
	me->set("weapon/or",o_name);		//记录制造原料
	me->set("weapon/value",0);		//记录武器升级已有的点数
	me->set("weapon/type",type);
	me->set("weapon/time",make_time);
	me->set("weapon/killed",0);

	weapon = new("/d/npc/m_weapon/weapon/m_weapon",1); 
	weapon->move(this_player());
	message_vision("$n摸起地上，带着斑斑血迹还有些烫手的巨"+type+"，说：\n"+type+"。。已。。成。。，$n的任务。。。也就完成了。。。。\n",me ,ob );
	message_vision("$n艰难的说：棒。。您。。收好，我该走了。。。\n",me,ob);
	ob->die();
// 生成武器完毕
  return 1;
}