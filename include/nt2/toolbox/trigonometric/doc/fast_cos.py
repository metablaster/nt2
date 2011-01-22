[ ##script manually modified
{
    'functor' : {       ## intrinsics values related to functor fast_cos
        'arity'         : '1',    ## functor number of parameters
        'ret_arity'     : '0',## must be '0' or omitted if not a tuple
        'types'         : ['real_'],     ## list of types string
        'rturn'         : { 'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type' },     ## ditionary of return types
        'call_types'    : [],## types used in call ['T']*arity if omitted 
        'type_defs'     : [],  ## supplementary typedefs
        }, ## end of functor
    'unit'    : {       ## informations for creating unit tests
        'global_header' : { ## header of machin.cpp
            'first_stamp' : 'created  by $author$ the $date$', ## creation stamp
            'stamp'       : 'modified by $author$ the $date$', ## modification stamp
            'included'    : ['#include <nt2/toolbox/trigonometric/include/constants.hpp>',
                             '#include <nt2/toolbox/crlibm/include/cos.hpp>'],     ## list of supplementary include directives
            'notes'       : [],        ## list of strings that will be included in a
                                            ## global comment
            },
        'specific_values' : {
                'real_'       : {
                    'nt2::Inf<T>()' :  {'result' : 'nt2::Nan<r_t>()'       ,'ulp_thresh':'0.5'},
                    'nt2::Minf<T>()':  {'result' : 'nt2::Nan<r_t>()'       ,'ulp_thresh':'0.5'},
                    'nt2::Nan<T>()' :  {'result' : 'nt2::Nan<r_t>()'       ,'ulp_thresh':'0.5'},
                    'nt2::Pi<T>()'  :  {'result' : 'nt2::Nan<r_t>()'      ,'ulp_thresh':'0.5'},
                    'nt2::Pi<T>()/2':  {'result' : 'nt2::Nan<r_t>()'      ,'ulp_thresh':'0.5'},
                    'nt2::Pi<T>()/4':  {'result' : 'nt2::Sqrt_2o_2<r_t>()' ,'ulp_thresh':'0.5'},
                    '-nt2::Pi<T>()'  : {'result' : 'nt2::Nan<r_t>()'      ,'ulp_thresh':'0.5'},
                    '-nt2::Pi<T>()/2': {'result' : 'nt2::Nan<r_t>()'      ,'ulp_thresh':'0.5'},
                    '-nt2::Pi<T>()/4': {'result' : 'nt2::Sqrt_2o_2<r_t>()' ,'ulp_thresh':'0.5'},
                    'nt2::Zero<T>()':  {'result' : 'nt2::One<r_t>()'       ,'ulp_thresh':'0.5'},
                },
                'signed_int_   ': {
                    'nt2::Zero<T>()': {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.5'},
                },
                'default': {
                    'nt2::Zero<T>()': {'result' : 'nt2::Zero<r_t>()','ulp_thresh':'0.5'},
                },
           },  ## dictionary of parameters and values to be tested
        'ranges'          :  {
             'real_'         : [["-nt2::Pi<T>()/4","nt2::Pi<T>()/4"]],
              },  ## dictionary of ranges for random tests
        'verif_test'      : { ## verification dictionary
            'property_call'   : {'real_' : ['nt2::fast_cos(a0)'],},  ## dictionary of calls per types
            'property_value'  : {'real_' : ['nt2::crlibm::cos<nt2::rn>(a0)'],}, ## dictionary of alternate calls
            'ulp_thresh'      : {'real_' : ['0.5'],},     ## validity thresholds(s)
        },  ## end of verif_test
    },  ## end of unit 
},
]
